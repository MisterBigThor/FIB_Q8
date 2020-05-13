--
-- Copyright (c) 2018, UPC
-- All rights reserved.
-- 

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.math_real.all;

use work.param_disenyo_pkg.all;
use work.tipos_constan_memoria_pkg.all;
use work.componentes_FMTE_pkg.all;
use work.cte_tipos_deco_camino_pkg.all;
use work.retardos_pkg.all;

entity alinearE is
port(ent: in tam_dat_camino_MD;
	opMD: in st_opMD;
	sal: out tam_dat_camino_MD);
end alinearE;

architecture estructural of alinearE is

subtype t_byte is std_logic_vector(tam_byte-1 downto 0);

-- senyales
	signal dir : std_logic_vector(1 downto 0);
	signal e0, e1, e2, e3 : t_byte;
	signal m01, m02, m13 : t_byte; 

begin
-- instanciacion 

	dir <= opMD(1 downto 0);
	e0 <= ent(7 downto 0);
	e1 <= ent(15 downto 8);
	e2 <= ent(23 downto 16);
	e3 <= ent(31 downto 24);
	
	mux01: mux2M generic map(tam_mux_datos=>tam_byte) port map(d0=>e0,d1=>e1,SEL=>dir(1),s=>m01); 
	mux02: mux2M generic map(tam_mux_datos=>tam_byte) port map(d0=>e0,d1=>e2,SEL=>dir(1),s=>m02); 
	mux13: mux2M generic map(tam_mux_datos=>tam_byte) port map(d0=>e1,d1=>e3,SEL=>dir(1),s=>m13); 
	
	sal <= m13&m02&m01&e0 after retFMTE;

end; 


