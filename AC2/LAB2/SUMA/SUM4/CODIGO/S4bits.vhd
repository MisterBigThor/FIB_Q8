--
-- Copyright (c) 2018, UPC
-- All rights reserved.
-- 

library ieee;		
use ieee.std_logic_1164.all;		
use work.all;		
		
-- La especificacion del componente en VHDL está en otro fichero
-- Los componentes se conectan mediante señales		
		
entity S4bits is 		
generic(ret_xor: time := 15 ns;
	ret_and: time := 10 ns;
	ret_or: time := 15 ns);
port (A: in std_logic_vector(3 downto 0);
	B: in std_logic_vector(3 downto 0);
	cen: in	std_logic;
	SUM: out std_logic_vector(3 downto 0);
	csal: out std_logic);
end S4bits;		
		
architecture estructural of S4bits is		
-- componentes y senyales 
	component s1bit generic (retardoxor : time; retardoand : time; retardoor : time);
	port (
			x: in std_logic;
			y: in std_logic;
			cen: in std_logic;
			s: out std_logic;
			csal: out std_logic
	);
	end component;
	signal c1, c2, c3 : std_logic;
	
begin
-- instanciacion e interconexiones		
	sum0: s1bit generic map (retardoxor => 15 ns,retardoand => 10 ns, retardoor => 15 ns)
	port map (x => A(0), y => B(0), cen => cen, csal => c1, s => SUM(0));
	sum1: s1bit generic map (retardoxor => 15 ns,retardoand => 10 ns, retardoor => 15 ns)
	port map (x => A(1), y => B(1), cen => c1, csal => c2, s => SUM(1));
	sum2: s1bit generic map (retardoxor => 15 ns,retardoand => 10 ns, retardoor => 15 ns)
	port map (x => A(2), y => B(2), cen => c2, csal => c3, s => SUM(2));
	sum3: s1bit generic map (retardoxor => 15 ns,retardoand => 10 ns, retardoor => 15 ns)
	port map (x => A(3), y => B(3), cen => c3, csal => csal, s => SUM(3));
	
end estructural;		

