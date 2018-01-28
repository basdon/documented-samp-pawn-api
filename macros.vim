
"a: make a link to function that's also documented around visual selected
let @a = 's<a href="#pa">pa</a>'

"z: make an external link around visual selected (from + register)
let @z = 's<a href=""+pa">pa</a>'

"r: add remarks on next line (from + register)
let @r = 'o/// <remarks>"+pa</remarks>'

"c: surround visual selected with bold code tags
let @c = 's<b><c><.€kb/c></b>hhhhhhhP'

"b: surround visual selected with bold tags
let @b = 's<b></b>hhhP'

"s: surround '..added in <version> and will not..' using b macro
let @s = '/added inwwv/andhh@b'

"v: paste remark and set samp version in bold (@r and @s)
let @v = '@r0@s'

"p: apply macro @c to a 0 and 1 on this line
let @p = '0/1@c0/0@c'

"o: apply macro @c to a true and false on this line
let @o = '0/trueve@c0/falseve@c'

