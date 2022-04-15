# Sovellusprojekti
eka books testi
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema netdb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema netdb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `netdb` DEFAULT CHARACTER SET utf8 ;
USE `netdb` ;

-- -----------------------------------------------------
-- Table `netdb`.`books`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `netdb`.`books` (
  `id_books` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(255) NULL,
  `author` VARCHAR(255) NULL,
  `isbn` VARCHAR(20) NULL,
  PRIMARY KEY (`id_books`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `netdb`.`user_table`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `netdb`.`user_table` (
  `id_user` INT NOT NULL AUTO_INCREMENT,
  `username` VARCHAR(20) NULL,
  `password` VARCHAR(255) NULL,
  PRIMARY KEY (`id_user`),
  UNIQUE INDEX `username_UNIQUE` (`username` ASC) VISIBLE)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;


