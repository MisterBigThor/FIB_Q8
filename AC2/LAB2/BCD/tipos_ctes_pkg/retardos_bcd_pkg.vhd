--
-- Copyright (c) 2018, UPC
-- All rights reserved.
-- 

library ieee;
use ieee.std_logic_1164.all;

package retardos_bcd_pkg is
--respuesta de 5.
--retsumbin + retmayor9 + retsumbin --> sumar 1 BCD [0,9]
--(sumar 1 BDC) * N --> suma N BCD [00,99] N=>2
-- suma N BCD + rets1bit + retc9 + retmux

constant retsumbin: time := 8 ns;
constant retmayor9: time := 1 ns;
constant rets1bit: time := 2 ns;
constant retc9: time := 2 ns;
constant retmux: time := 2 ns;
constant retBCDaDPD: time := 1 ns;
constant retDPDaBCD: time := 1 ns;

end package retardos_bcd_pkg;

