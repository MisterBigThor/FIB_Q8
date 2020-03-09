--
-- Copyright (c) 2018, UPC
-- All rights reserved.
-- 

library ieee;
use ieee.std_logic_1164.all;
use work.cte_tipos_bcd_pkg.all;
use work.componentes_digito_bcd_pkg.all;

entity s1bcd is
port (X: in st_bcd;
	Y: in st_bcd;
	cen: in std_logic;
	S: out st_bcd;
	csal: out std_logic);
end s1bcd;

architecture compor of s1bcd is 
-- senyales
	signal sumaBinA, resultadoMas9, sumaBinB : st_bcd;
	signal sumaBinAconcatCsalA: st_bcd_mas_1;
	signal csalA, csalMas9, csalB: std_logic;
begin

	sumadorA: snbits port map (X=>X, Y=>Y, cen=> cen, sum=>sumaBinA, csal => csalA);
	sumaBinAconcatCsalA <= csalA & sumaBinA;
	m9: mayor9 port map(X=>sumaBinAconcatCsalA, S=>resultadoMas9, csal=> csal);
	sumadorB: snbits port map(X=>sumaBinA, Y=>resultadoMas9, cen=> '0', sum=>S);
end;

