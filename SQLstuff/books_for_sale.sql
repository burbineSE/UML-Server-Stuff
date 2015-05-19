-- phpMyAdmin SQL Dump
-- version 4.0.4.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Feb 23, 2014 at 08:31 PM
-- Server version: 5.6.11
-- PHP Version: 5.5.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `book_slice1`
--

-- --------------------------------------------------------

--
-- Table structure for table `books_for_sale`
--

CREATE TABLE IF NOT EXISTS `books_for_sale` (
  `index` bigint(20) NOT NULL AUTO_INCREMENT,
  `isbn` text NOT NULL,
  `seller` text NOT NULL,
  `asking_price` decimal(10,2) NOT NULL,
  PRIMARY KEY (`index`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `books_for_sale`
--

INSERT INTO `books_for_sale` (`index`, `isbn`, `seller`, `asking_price`) VALUES
(1, '0132346605', 'cburbine', '85.25'),
(2, '0135072956', 'cburbine', '110.75');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
