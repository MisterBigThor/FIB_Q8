--

-- Copyright (c) 2018, UPC
-- All rights reserved.
-- 

library ieee;		
use ieee.std_logic_1164.all;		
use work.all;		
		
-- La especificación del componente en VHDL está en otro fichero 
-- Los componentes se conectan mediante un vector de señales		
		
entity snbits is
	generic (tam: positive:= 4);
	port (a: in std_logic_vector(tam-1 downto 0);
		b: in std_logic_vector(tam-1 downto 0);
		cen: in std_logic;
		s: out std_logic_vector(tam-1 downto 0);
		csal: out std_logic );
end snbits;

architecture estructural of snbits is
	component s1bit
		generic(retardoxor: time;retardoand: time;retardoor: time);
		port (x: in std_logic; y: in std_logic; cen: in std_logic;
			s: out std_logic; csal: out std_logic);
	end component;

--senyales para las conexiones
	signal c : std_logic_vector (tam downto 0);
begin
-- instanciacion de componentes e interconexion
	c(0) <= cen;
	sumadorN: for i in 0 to tam-1
	generate
		sumi: s1bit generic map(retardoxor =>15 ns, retardoand => 10 ns, retardoor => 15ns)
						port map(x=>a(i), y=>b(i), cen=>c(i), s=>s(i), csal=>c(i+1));
	end generate;
	csal <= c(tam);
	
end estructural;
