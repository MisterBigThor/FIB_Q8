- És va escollir per l'adquisició del sistema el model de processador amb una millor **eficiència energètica \**(Flops/Watt)\****?

  $E_{eff} = \frac{Flops}{Watt} = \frac{frec*\text{op's_per_cycle}*\text{cores_socket}}{powerSocket}$

  $E_{eff}^{E5645} = \frac{2.40GHz*\frac{128}{64}*6}{80} = \frac{2.88*10^{10} Flops}{80} = 360 MFlops/W$

  $E_{eff}^{X6550} = \frac{2.0GHz*2*8}{130W} = \frac{3.2*10^{10}Flops}{130W} = 246 MFlops/W$

  $E_{eff}^{X5667} = \frac{3.06GHz*2*4}{95} = \frac{2.45 *10^{10}Flops}{95} = 257.89MFlops/W$

  Podem veure amb les dades, que s'ha escollit el millor la millor alternativa.

- Dibuixar el **roofline model** del sistema adquirit format per processador/memòria, incloent tant accés local com remot als DIMMs de memòria.

  Al cluster tenim que els flops de pic son 2.88 GFLOPS/cycle,  els periferics que tenim son:

  * 2 ports QPI@2.93 GHz serveixen ($2.93GHz*2bits/Hz*16bits*2direction*2portsQPI$) 46.88GBytes/s 
  * 6 DIMM de 4GB, DDR-1333,  ??
  * 4 HDD 2T SATA amb 6GB/s

  > Em sap greu Eduard pero no soc capaç de fer el dibuix del roofline.

- Calcular **l'eficiència energètica** del node senser obtinguda si considerem que el TDP de cadascun dels DIMMs és 5W, de cadascun dels discs HDD és 4 W i que la placa base amb la resta de components té un TDP de 35W.

  $E_{eff}^{node} = \frac{Flops}{Watt} = \frac{2.88*10^{10}}{80W+(5W*6\text{ DIMMs})+(4W*4\text{ HDD})+35W} = \frac{2.88*10^{10}}{161W} = 178.8 MFlops/W$

