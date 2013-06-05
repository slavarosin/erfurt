SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL';

CREATE SCHEMA IF NOT EXISTS `erfurt` DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci ;
USE `erfurt`;

-- -----------------------------------------------------
-- Table `erfurt`.`address`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `erfurt`.`shipment` ;

CREATE TABLE IF NOT EXISTS `erfurt`.`shipment` (
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
	REFERENCES `erfurt`.`address` (`id` )
	ON DELETE NO ACTION
	ON UPDATE NO ACTION)
ENGINE = InnoDB;

-- -----------------------------------------------------
-- Table `erfurt`.`user`
-- -----------------------------------------------------


-- -----------------------------------------------------
-- Table `erfurt`.`shipment`
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Table `erfurt`.`carrier`
-- -----------------------------------------------------



SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;