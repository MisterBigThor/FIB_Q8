
library ieee; 
use ieee.std_logic_1164.all;

entity s1bit is port( 
	x, y : in std_logic;
	cen: in std_logic;
	s: out std_logic;
	csal: out std_logic );
end s1bit;


architecture halfAdder of s1bit is
	constant retardoxor: time := 15 ns;
	constant retardoand: time := 10 ns;
	constant retardoor: time := 15 ns;
	signal xorxy, andxy, andxorxyz : std_logic;
	
begin
	xorxy <= x xor y after retardoxor;
	andxy <= x and y after retardoand;
	
	andxorxyz <= cen and xorxy after retardoand;
	
	s <= xorxy xor cen after retardoxor;
	csal <= andxy or andxorxyz after retardoor;
end halfAdder;
