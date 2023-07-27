# el3105_2023_1_g9
# Grupo-9
# Se utilizaron los siguientes modulos: RAK19001 WisBlock Dual IO Base Board, RAK5860 WisBlock NB-IoT Interface Module, RAK11200 WisBlock WiFi Module, RAK1904 WisBlock 3-axis Acceleration Sensor Module.
# Nombre y contacto de los integrantes
# Simón Arenas, simon.arenas@ug.uchile.cl
# Joaquín Camhi, joaquin.camhi@ug.uchile.cl
# Diego Ortiz de Zarate, ortizdiegomt@gmail.com

# El dispositivo consturido con esos bloques tiene la finalidad de leer la aceleración de una persona, detectando una caída si está supera cierto limite, para ello, si dicho limite es superado se envían los mensajes con aceleración, además de una variable risk=1, si no, se envían de igual manera los mensajes, pero risk=0. El código que contiene la inicialización, la medicioón y el envío del mensaje se encuentra en la carpeta proyecto, en src.
