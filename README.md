CREATE DATABASE netdb;
CREATE USER 'netuser'@'localhost' IDENTIFIED WITH mysql_native_password BY 'netpass';
GRANT ALL on netdb.* to 'netuser'@'localhost';

USE netdb;

CREATE TABLE book(
id_book INT primary key auto_increment,
name VARCHAR(255),
author VARCHAR(255),
isbn VARCHAR(20)
);

INSERT INTO book(name,author,isbn) VALUES('PHP Basic','Bob Jones','123-456-789-111-x');
INSERT INTO book(name,author,isbn) VALUES('Statistics','Lisa Smith','222-333-444-555-y');

CREATE TABLE car (
  id_car INT primary key auto_increment,
  brand varchar(255),
  model varchar(255) 
);

INSERT INTO car(brand,model) VALUES('Citroen', 'Xantia');
INSERT INTO car(brand,model) VALUES('Peugeot', '307');
INSERT INTO car(brand,model) VALUES('Hyundai', 'Coupe');
INSERT INTO car(brand,model) VALUES('Renaul', 'Megane');
INSERT INTO car(brand,model) VALUES('Opel', 'Vectra');
INSERT INTO car(brand,model) VALUES('Ford', 'Transit');
INSERT INTO car(brand,model) VALUES('Tesla', 'Model X');