
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

