SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL';

-- CREATE SCHEMA IF NOT EXISTS `neadekvat_erfurt` DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci ;

-- -----------------------------------------------------
-- Table `address`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `address` ;

CREATE TABLE IF NOT EXISTS `address` (
	`id` INT NOT NULL AUTO_INCREMENT ,
	`email` VARCHAR(45) NOT NULL ,
	`company_name` VARCHAR(64) NULL ,
	`contact_person_name` VARCHAR(64) NOT NULL ,
	`contact_person_position` VARCHAR(64) NULL ,
	`city` VARCHAR(45) NOT NULL ,
	`street1` VARCHAR(45) NOT NULL ,
	`street2` VARCHAR(45) NOT NULL ,
	`state` VARCHAR(2) NOT NULL ,
	`zip` VARCHAR(16) NOT NULL ,
	PRIMARY KEY (`id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `user`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `user` ;

CREATE TABLE IF NOT EXISTS `user` (
	`id` INT NOT NULL AUTO_INCREMENT ,
	`username` VARCHAR(45) NOT NULL ,
	`passwd` VARCHAR(32) NOT NULL ,
	`carrier` VARCHAR(64) NULL ,
	`expenses` VARCHAR(64) NULL ,
	`pickup_route` BOOLEAN NOT NULL ,
	`internationally` BOOLEAN NOT NULL ,
	`amount` VARCHAR(64) NULL ,
	`address_id` INT NULL ,
	`role` VARCHAR(5) NOT NULL ,
	`phone` VARCHAR(24) NOT NULL ,
	`cell_phone` VARCHAR(24) NULL ,
	`fax` VARCHAR(24) NULL ,
	`referal_id` INT NULL ,
	PRIMARY KEY (`id`) ,
	UNIQUE INDEX `username` (`username` ASC),
	INDEX `fk_users_address` (`address_id` ASC) ,
	CONSTRAINT `fk_users_address`
    FOREIGN KEY (`address_id` )
    REFERENCES `address` (`id` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_unicode_ci;

-- -----------------------------------------------------
-- Table `shipment`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `shipment` ;

CREATE TABLE IF NOT EXISTS `shipment` (
	`id` INT NOT NULL AUTO_INCREMENT ,
	`service_type` INT NOT NULL ,
	`order_id` VARCHAR(32) NOT NULL ,
	`sender_address_id` INT NOT NULL ,
	`receiver_address_id` INT NOT NULL ,
	`carrier` VARCHAR(64) NULL,
	`description` TEXT NOT NULL ,
	`weight` VARCHAR(45) NULL ,
	`value` VARCHAR(45) NULL ,
	`date` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ,
	`status` INT NOT NULL DEFAULT 0,
	PRIMARY KEY (`id`) ,
	INDEX `fk_shipment_address` (`sender_address_id` ASC) ,
	INDEX `fk_shipment_address1` (`receiver_address_id` ASC) ,
	CONSTRAINT `fk_shipment_address`
	FOREIGN KEY (`sender_address_id` )
	REFERENCES `address` (`id` )
	ON DELETE NO ACTION
	ON UPDATE NO ACTION,
	CONSTRAINT `fk_shipment_address1`
	FOREIGN KEY (`receiver_address_id` )
	REFERENCES `address` (`id` )
	ON DELETE NO ACTION
	ON UPDATE NO ACTION)
ENGINE = InnoDB;

-- -----------------------------------------------------
-- Table `carrier`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `carrier` ;

CREATE  TABLE IF NOT EXISTS `carrier` (
	`id` INT NOT NULL AUTO_INCREMENT ,
	`name` VARCHAR(45) NULL ,
	PRIMARY KEY (`id`) )
ENGINE = InnoDB;
-- -----------------------------------------------------
-- Table `trans`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `trans` ;

CREATE TABLE IF NOT EXISTS `trans`(
	`id` INT NOT NULL AUTO_INCREMENT ,
	`sum` DECIMAL(18,2) NOT NULL ,
	`comment` VARCHAR(45) NULL,
	`client_id` INT NOT NULL ,
	CONSTRAINT `client_id`
	FOREIGN KEY (`client_id` )
	REFERENCES `user` (`id` )
	ON DELETE NO ACTION
	ON UPDATE NO ACTION,
PRIMARY KEY (`id`) )
ENGINE = InnoDB;

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;