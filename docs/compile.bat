pawncc.exe "-(-" "-;-" -i../ main.pwn -rmain.xml 
pawncc.exe "-(-" "-;-" -i../ npc.pwn -rnpc.xml 
sed -i 's/xml-stylesheet href="[^"]*"/xml-stylesheet href="pawndoc.xsl"/' main.xml
sed -i 's/xml-stylesheet href="[^"]*"/xml-stylesheet href="pawndoc.xsl"/' npc.xml
