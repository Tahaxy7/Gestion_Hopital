#include "rendezvousdialog.h"
#include "ui_rendezvousdialog.h"
#include "rendezvousmanager.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

// Constructeur
RendezVousDialog::RendezVousDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RendezVousDialog)
{
    ui->setupUi(this);

    remplirComboBoxPatients();
    remplirComboBoxMedecins();

    connect(ui->btnAjouter, &QPushButton::clicked, this, &RendezVousDialog::ajouterRendezVous);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &RendezVousDialog::supprimerRendezVous);

    ui->btnAjouter->setIcon(QIcon(":/icons/ajouter.png"));
    ui->btnSupprimer->setIcon(QIcon(":/icons/supprimer.png"));


    chargerRendezVous();
}

// Destructeur
RendezVousDialog::~RendezVousDialog() {
    delete ui;
}

// Remplir les patients par nom dans la QComboBox
void RendezVousDialog::remplirComboBoxPatients() {
    QSqlQuery query("SELECT id_patient, nom || ' ' || prenom AS nom_complet FROM Patients");
    while (query.next()) {
        int id = query.value("id_patient").toInt();
        QString nomComplet = query.value("nom_complet").toString();
        ui->comboBoxPatient->addItem(nomComplet, id);  // Ajouter nom complet avec ID comme donnée associée
    }
}
// Remplir les medcins par nom dans la QComboBox

void RendezVousDialog::remplirComboBoxMedecins() {
    QSqlQuery query("SELECT id_medecin, nom || ' ' || prenom AS nom_complet FROM Medecins");
    while (query.next()) {
        int id = query.value("id_medecin").toInt();
        QString nomComplet = query.value("nom_complet").toString();
        ui->comboBoxMedecin->addItem(nomComplet, id);  // Ajouter nom complet avec ID
    }
}


// Ajouter un rendez-vous avec les noms (recherche d'ID par sous-requête)
void RendezVousDialog::ajouterRendezVous() {
    QString nomCompletPatient = ui->comboBoxPatient->currentText();
    QString nomCompletMedecin = ui->comboBoxMedecin->currentText();
    QString date = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString heure = ui->timeEdit->time().toString("HH:mm");
    QString motif = ui->textEditMotif->toPlainText();

    if (nomCompletPatient.isEmpty() || nomCompletMedecin.isEmpty() || date.isEmpty() || heure.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return;
    }

    int id_patient = -1;
    int id_medecin = -1;

    QSqlQuery query;

    // Récupération de l'ID patient par nom complet
    query.prepare("SELECT id_patient FROM Patients WHERE nom || ' ' || prenom = :nom_patient");
    query.bindValue(":nom_patient", nomCompletPatient);
    if (query.exec() && query.next()) {
        id_patient = query.value(0).toInt();
    } else {
        QMessageBox::critical(this, "Erreur", "Patient introuvable.");
        return;
    }

    // Récupération de l'ID médecin par nom complet
    query.prepare("SELECT id_medecin FROM Medecins WHERE nom || ' ' || prenom = :nom_medecin");
    query.bindValue(":nom_medecin", nomCompletMedecin);
    if (query.exec() && query.next()) {
        id_medecin = query.value(0).toInt();
    } else {
        QMessageBox::critical(this, "Erreur", "Médecin introuvable.");
        return;
    }

    // Insertion du rendez-vous
    query.prepare("INSERT INTO RendezVous (id_patient, id_medecin, date_rdv, heure_rdv, motif) "
                  "VALUES (:id_patient, :id_medecin, :date, :heure, :motif)");
    query.bindValue(":id_patient", id_patient);
    query.bindValue(":id_medecin", id_medecin);
    query.bindValue(":date", date);
    query.bindValue(":heure", heure);
    query.bindValue(":motif", motif);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Rendez-vous ajouté avec succès.");
        chargerRendezVous();
    } else {
        QMessageBox::critical(this, "Erreur SQL", "L'ajout a échoué : " + query.lastError().text());
    }
}





// Supprimer un rendez-vous
void RendezVousDialog::supprimerRendezVous() {
    int row = ui->tableWidgetRendezVous->currentRow();  // Obtenir la ligne sélectionnée
    if (row == -1) {
        QMessageBox::warning(this, "Sélection requise", "Veuillez sélectionner un rendez-vous à supprimer.");
        return;
    }

    // Récupérer l'ID du rendez-vous à partir de la première colonne
    int id_rdv = ui->tableWidgetRendezVous->item(row, 0)->text().toInt();

    // Confirmation de suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer ce rendez-vous ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) return;

    // Gestionnaire de suppression
    RendezVousManager manager;
    if (manager.supprimerRendezVous(id_rdv)) {
        QMessageBox::information(this, "Succès", "Rendez-vous supprimé avec succès.");
        chargerRendezVous();  // Recharger la table après suppression
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du rendez-vous.");
    }
}


// Charger et afficher les rendez-vous dans la table
void RendezVousDialog::chargerRendezVous() {
    ui->tableWidgetRendezVous->setRowCount(0);
    ui->tableWidgetRendezVous->setColumnCount(6);

    QStringList headers = {"ID", "Patient", "Médecin", "Date", "Heure", "Motif"};
    ui->tableWidgetRendezVous->setHorizontalHeaderLabels(headers);

    QSqlQuery query(
        "SELECT rv.id_rdv, "
        "p.nom || ' ' || p.prenom AS patient, "
        "m.nom || ' ' || m.prenom AS medecin, "
        "rv.date_rdv, rv.heure_rdv, rv.motif "
        "FROM RendezVous rv "
        "JOIN Patients p ON rv.id_patient = p.id_patient "
        "JOIN Medecins m ON rv.id_medecin = m.id_medecin"
        );

    int row = 0;
    while (query.next()) {
        ui->tableWidgetRendezVous->insertRow(row);
        ui->tableWidgetRendezVous->setItem(row, 0, new QTableWidgetItem(query.value("id_rdv").toString()));
        ui->tableWidgetRendezVous->setItem(row, 1, new QTableWidgetItem(query.value("patient").toString()));
        ui->tableWidgetRendezVous->setItem(row, 2, new QTableWidgetItem(query.value("medecin").toString()));
        ui->tableWidgetRendezVous->setItem(row, 3, new QTableWidgetItem(query.value("date_rdv").toString()));
        ui->tableWidgetRendezVous->setItem(row, 4, new QTableWidgetItem(query.value("heure_rdv").toString()));
        ui->tableWidgetRendezVous->setItem(row, 5, new QTableWidgetItem(query.value("motif").toString()));

        // Cacher la colonne ID
        ui->tableWidgetRendezVous->setColumnHidden(0, true);
        row++;
    }
}

