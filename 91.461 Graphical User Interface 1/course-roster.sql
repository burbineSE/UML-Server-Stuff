-- phpMyAdmin SQL Dump
-- version 4.0.4.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Dec 04, 2013 at 07:23 PM
-- Server version: 5.6.11
-- PHP Version: 5.5.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `roster`
--

-- --------------------------------------------------------

--
-- Table structure for table `course-roster`
--

CREATE TABLE IF NOT EXISTS `course-roster` (
  `index` bigint(20) NOT NULL AUTO_INCREMENT,
  `lastname` text NOT NULL,
  `firstname` text NOT NULL,
  `major` text NOT NULL,
  `email` text NOT NULL,
  PRIMARY KEY (`index`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=51 ;

--
-- Dumping data for table `course-roster`
--

INSERT INTO `course-roster` (`index`, `lastname`, `firstname`, `major`, `email`) VALUES
(1, 'Arribasplata', 'Ana C.', 'Computer Science (BS)', 'ana_arribasplata@student.uml.edu'),
(2, 'Baillie', 'Colin Domigan', 'Computer Science (BS)', 'domigan16@gmail.com'),
(3, 'Bet-Eivazi', 'Joseph Alexander', 'Computer Science (BS) / Business (Minor)', 'josephbet75@gmail.com'),
(4, 'Burbine', 'Christopher', 'Computer Science (BS)', 'christopher_burbine@student.uml.edu'),
(5, 'Cadwallader', 'Robert M.', 'Computer Science (BS)', 'robertcadwallader@gmail.com'),
(6, 'Calandriello', 'Eric Matthew', 'Computer Science (BS)', 'ecal777@gmail.com'),
(7, 'Cao', 'Benjamin J.', 'Computer Science (BS)', 'benjamin_cao@student.uml.edu'),
(8, 'Caravetta', 'Joshua David', 'Electrical Engineering (BSE)', 'joshua_caravetta@student.uml.edu'),
(9, 'Carcia', 'Kaitlyn Paula', 'Computer Science (BS) / Business (Minor)', 'kate.carcia@gmail.com'),
(10, 'Chau', 'Thuan S.', 'Business Administration (BBA) / Computer Science (Minor)', 'sathaun_chau@student.uml.edu'),
(11, 'Cohen', 'Timothy Richard', 'Computer Science (BS)', 'timothy_cohen@student.uml.edu'),
(12, 'Compton', 'Christopher James', 'Computer Science (BS)', 'christopher_compton@student.uml.edu'),
(13, 'Crowe', 'Stephen Michael', 'Computer Science (BS)', 'stephen_crowe@student.uml.edu'),
(14, 'Darling', 'Nicholas Richard', 'Computer Science (BS)', 'mrostitat@gmail.com'),
(15, 'Dupuis', 'Robert Andrew', 'Computer Science (BS)', 'robert_dupuis@student.uml.edu'),
(16, 'Estrada', 'Joshua Alan Manalastas', 'Computer Science (BS)', 'JoshuaAlan_Estrada@student.uml.edu'),
(17, 'Flanz', 'Adam Benjamin', 'Computer Science (BS)', 'adam_flanz@student.uml.edu'),
(18, 'Gainley', 'Brianna Theresa', 'Computer Science (BS)', 'brigainley@gmail.com'),
(19, 'Heng', 'Bunlong', 'Computer Science (BS)', 'bunlong_heng@student.uml.edu'),
(20, 'Hu', 'Yaxing', 'Computer Science (BS)', 'yaxing_hu@student.uml.edu'),
(21, 'Huston', 'John', 'Computer Science (BS)', 'jhuston@cs.uml.edu'),
(22, 'Jelley', 'David', 'Computer Science (BS)', 'david_jelley1@student.uml.edu'),
(23, 'Kolsoi', 'Daniel John', 'Computer Science (BS)', 'daniel_kolsoi@student.uml.edu'),
(24, 'Landskov', 'Erik Lee', 'Computer Science (BS)', 'erik_landskov@student.uml.edu'),
(25, 'Lincoln', 'Andrew Forbes', 'Computer Science (BS)', 'andrew_lincoln@student.uml.edu'),
(26, 'Milhomme', 'Andi Rosario', 'Computer Science (BS)', 'mandirosa3@gmail.com'),
(27, 'Morris', 'Cameron Ryan', 'Computer Science (BS)', 'cameron_morris@student.uml.edu'),
(28, 'Mutunga', 'Norman M.', 'Computer Science (BS)', 'mbalukakithi@gmail.com'),
(29, 'Nappi', 'Jacob Mathew', 'Computer Science (BS)', 'Jacob_Nappi@student.uml.edu'),
(30, 'Patel', 'Akash Dhiraj', 'Computer Science (BS)', 'akash_patel@student.uml.edu'),
(31, 'Prak', 'Corey David', 'Computer Science (BS)', 'corey.prak@gmail.com'),
(32, 'Quintal', 'Curtis Manuel', 'Computer Science (BS)', 'curtis_quintal@student.uml.edu'),
(33, 'Saade', 'Hady C.', 'Computer Science (BS)', 'hady.k.saade@gmail.com'),
(34, 'Saras', 'Gregory Stephen', 'Computer Science (BS)', 'gregory_saras@student.uml.edu'),
(35, 'Soeltz', 'William', 'Fine Arts (BFA) / Computer Science (Minor)', 'william_soeltzszoets@student.uml.edu'),
(36, 'Stickney', 'Patrick', 'Computer Science (BS)', 'patrick_stickney@student.uml.edu'),
(37, 'St. Pierre', 'Nicholas Ryan', 'Computer Science (BS)', 'nstpierr@cs.uml.edu'),
(38, 'Tran', 'Thu Anh', 'Computer Science (BS)', 'thu_tran2@student.uml.edu'),
(39, 'Warren', 'Nicholas Tristan', 'Computer Science (BS)', 'nicholas_warren@student.uml.edu'),
(40, 'Weiss', 'Bryan', 'Computer Science (BS)', 'bryan_weiss@student.uml.edu'),
(50, 'Weiss', 'Bryan', 'Computer Science (BS)', 'bryan_weiss@student.uml.edu');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
