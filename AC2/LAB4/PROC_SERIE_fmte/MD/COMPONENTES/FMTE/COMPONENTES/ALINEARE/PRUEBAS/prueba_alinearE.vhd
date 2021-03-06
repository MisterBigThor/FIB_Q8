

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.tipos_constan_memoria_pkg.all;
use work.cte_tipos_deco_camino_pkg.all;

entity prueba_alinearE is 

end prueba_alinearE;

architecture compor of prueba_alinearE is

component alinearE is
port(ent: in tam_dat_camino_MD;
	opMD: in st_opMD;
	sal: out tam_dat_camino_MD);
end component;

signal ent, sal: tam_dat_camino_MD;
signal reloj: std_logic;
signal opMD: st_opMD;

alias E0: std_logic_vector(7 downto 0) is ent(7 downto 0); 
alias E1: std_logic_vector(7 downto 0) is ent(15 downto 8); 
alias E2: std_logic_vector(7 downto 0) is ent(23 downto 16); 
alias E3: std_logic_vector(7 downto 0) is ent(31 downto 24); 

constant T: time := 20 ns;

begin

formaEscr: alinearE port map(ent => ent, opMD => opMD, sal => sal);

impulsos: process is
begin
	wait for T;
	E0 <= x"00";
	E1 <= x"01";
	E2 <= x"02";
	E3 <= x"03";
	opMD(1 downto 0) <= b"10";
	wait for T;
	report "entrada " & integer'image(to_integer(unsigned(ent(31 downto 0))));
	report "salida " & integer'image(to_integer(unsigned(sal(31 downto 0))));

	opMD(1 downto 0) <= b"00";
	wait for T;
	assert (sal(15 downto 8) = E0) report "incorret out in byte" severity failure;
	
	opMD(1 downto 0) <= b"01";
	wait for T;
	assert (sal(15 downto 0) = E1&E0) report "incorret out int halfword" severity failure;
	
   report "Comprobacion finalizada." severity note;
   wait;
end process;

end;

