"../zeex compiler/pawnc-3.10.4-windows/bin/pawncc.exe" -(- -;- -i../documented-samp-pawn-api/ main.pwn -rmain.xml 
"../zeex compiler/pawnc-3.10.4-windows/bin/pawncc.exe" -(- -;- -i../documented-samp-pawn-api/ npc.pwn -rnpc.xml 
sed -i 's/xml-stylesheet href="[^"]*"/xml-stylesheet href="pawndoc.xsl"/' main.xml
sed -i 's/xml-stylesheet href="[^"]*"/xml-stylesheet href="pawndoc.xsl"/' npc.xml
