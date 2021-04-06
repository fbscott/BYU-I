/******************************************************************************
 * Drop all tables before adding
 *****************************************************************************/
DROP TABLE IF EXISTS studentdb.pres_details;
DROP TABLE IF EXISTS studentdb.quote;
DROP TABLE IF EXISTS studentdb.document_signer;
DROP TABLE IF EXISTS studentdb.ticket;
DROP TABLE IF EXISTS studentdb.military_branch;
DROP TABLE IF EXISTS studentdb.pres;
DROP TABLE IF EXISTS studentdb.vice_pres;
DROP TABLE IF EXISTS studentdb.first_lady;
DROP TABLE IF EXISTS studentdb.party;
DROP TABLE IF EXISTS studentdb.document;
DROP TABLE IF EXISTS studentdb.state;
DROP TABLE IF EXISTS studentdb.reason_left_office;

/******************************************************************************
 * Create all tables
 *****************************************************************************/
CREATE TABLE IF NOT EXISTS studentdb.pres (
   pres_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
   first VARCHAR(80) NOT NULL,
   middle VARCHAR(80),
   last VARCHAR(80) NOT NULL
);

CREATE TABLE IF NOT EXISTS studentdb.vice_pres (
   vice_pres_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
   first VARCHAR(80) NOT NULL,
   middle VARCHAR(80),
   last VARCHAR(80) NOT NULL
);

CREATE TABLE IF NOT EXISTS studentdb.first_lady (
   first_lady_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
   first VARCHAR(80) NOT NULL,
   middle VARCHAR(80),
   last VARCHAR(80) NOT NULL
);

CREATE TABLE IF NOT EXISTS studentdb.party (
   party_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
   name VARCHAR(80) NOT NULL,
   CONSTRAINT uc_party UNIQUE (name)
);

CREATE TABLE IF NOT EXISTS studentdb.document (
   document_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
   title VARCHAR(80) NOT NULL,
   CONSTRAINT uc_document UNIQUE (title)
);

CREATE TABLE IF NOT EXISTS studentdb.state (
   state_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
   name VARCHAR(80) NOT NULL,
   CONSTRAINT uc_state UNIQUE (name)
);

CREATE TABLE IF NOT EXISTS studentdb.reason_left_office (
   reason_left_office_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
   reason VARCHAR(80) NOT NULL,
   CONSTRAINT uc_reason_left_office UNIQUE (reason)
);

CREATE TABLE IF NOT EXISTS studentdb.military_branch (
   military_branch_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
   branch VARCHAR(80) NOT NULL,
   CONSTRAINT uc_military_branch UNIQUE (branch)
);

CREATE TABLE IF NOT EXISTS studentdb.ticket (
    ticket_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    pres_id INT NOT NULL,
    vice_pres_id INT,
    party_id INT NOT NULL,
    slogan VARCHAR(80),
    CONSTRAINT fk_ticket_pres
        FOREIGN KEY(pres_id) 
            REFERENCES studentdb.pres(pres_id),
    CONSTRAINT fk_ticket_vice_pres
        FOREIGN KEY(vice_pres_id) 
            REFERENCES studentdb.vice_pres(vice_pres_id),
    CONSTRAINT fk_ticket_party
        FOREIGN KEY(party_id) 
            REFERENCES studentdb.party(party_id)
);

CREATE TABLE IF NOT EXISTS studentdb.document_signer (
    document_signer_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    document_id INT NOT NULL,
    pres_id INT NOT NULL,
    CONSTRAINT fk_document_signer_document
        FOREIGN KEY(document_id) 
            REFERENCES studentdb.document(document_id),
    CONSTRAINT fk_document_signer_pres
        FOREIGN KEY(pres_id) 
            REFERENCES studentdb.pres(pres_id)
);

CREATE TABLE IF NOT EXISTS studentdb.quote (
    quote_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    pres_id INT NOT NULL,
    CONSTRAINT fk_quote_pres
        FOREIGN KEY(pres_id) 
            REFERENCES studentdb.pres(pres_id)
);

CREATE TABLE IF NOT EXISTS studentdb.pres_details (
    pres_details_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    pres_id INT NOT NULL,
    vice_pres_id INT,
    party_id INT NOT NULL,
    state_id INT NOT NULL,
    terms_served INT NOT NULL,
    reason_left_office_id INT NOT NULL,
    military_branch_id INT,
    first_lady_id INT,
    living BOOLEAN NOT NULL,
    CONSTRAINT fk_pres_details_pres
        FOREIGN KEY(pres_id) 
            REFERENCES studentdb.pres(pres_id),
    CONSTRAINT fk_pres_details_vice_pres
        FOREIGN KEY(vice_pres_id) 
            REFERENCES studentdb.vice_pres(vice_pres_id),
    CONSTRAINT fk_pres_details_party
        FOREIGN KEY(party_id) 
            REFERENCES studentdb.party(party_id),
    CONSTRAINT fk_pres_details_state
        FOREIGN KEY(state_id) 
            REFERENCES studentdb.state(state_id),
    CONSTRAINT fk_pres_details_reason_left_office
        FOREIGN KEY(reason_left_office_id) 
            REFERENCES studentdb.reason_left_office(reason_left_office_id),
    CONSTRAINT fk_pres_details_military_branch
        FOREIGN KEY(military_branch_id) 
            REFERENCES studentdb.military_branch(military_branch_id),
    CONSTRAINT fk_pres_details_first_lady
        FOREIGN KEY(first_lady_id) 
            REFERENCES studentdb.first_lady(first_lady_id)
);
