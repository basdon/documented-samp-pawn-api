cp ../pawndocimproved/pawndoc.xsl ./pawndoc.xsl 2>/dev/null
pawncc.exe "-(-" "-;-" -i../documented-samp-pawn-api/ main.pwn -rmain.xml
pawncc.exe "-(-" "-;-" -i../documented-samp-pawn-api/ npc.pwn -rnpc.xml
sed -i 's/xml-stylesheet href="[^"]*"/xml-stylesheet href="pawndoc.xsl"/' main.xml
sed -i 's/xml-stylesheet href="[^"]*"/xml-stylesheet href="pawndoc.xsl"/' npc.xml
