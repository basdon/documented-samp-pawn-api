<!DOCTYPE html>
<html>
<head>
	<title>PawnoDOC</title>
	<meta http-equiv="X-UA-Compatible" content="IE=9" />
	<meta http-equiv="imagetoolbar" content="no" />
	<meta http-equiv="content-type" content="text/html; charset=UTF-8" />
	<meta http-equiv="content-language" content="en" />
	<meta name="viewport" content="width=device-width"/>
	<meta charset="utf-8" />
	<style type="text/css">
		body > div {
			width: 50%;
			padding: 2em;
			margin: auto auto;
		}
		textarea {
			width: 50vw;
			height: 30vh;
		}
		textarea,
		textarea:hover,
		textarea:active {
			outline: none !important;
		}
	</style>
</head>
<body>
	<div>
		<form method="post">
			<textarea name="params"></textarea>
			<input type="submit"/>
		</form>
		<?php
			if (isset($_POST['params']))
			{
				$lines = explode("\r\n", $_POST['params']);
				
				$type = "";
				
				ob_start();
				
				$returns = array();
				
				echo "<span id=\"copy\"><br/>";
				foreach ($lines as $line)
				{
					$line = trim($line);
					if ($line == "Description:")
					{
						$type = "d";
						continue;
					}
					if ($line == "Parameters:")
					{
						$type = "p";
						continue;
					}
					if ($line == "Return Values:")
					{
						$type = "r";
						continue;
					}
					if ($line == "Example Usage:")
					{
						$type = "i";
						continue;
					}
					if ($line == "Related Functions")
					{
						$type = "f";
						continue;
					}
					if ($line == "Related Callbacks")
					{
						$type = "c";
						continue;
					}
					if (substr($line, 0, 6) == "Image:")
					{
						$type = "i";
						continue;
					}
					if ($line == "" || $line == "[edit]")
					{
						continue;
					}

					if ($type == "i") {
						continue;
					}
					
					if ($type == "d")
					{
						if(substr($line, -1) != ".") $line .= ".";
						echo("/// &ltsummary&gt{$line}&lt/summary&gt<br/>");
						$type = "2";
					}
					
					if ($type == "p")
					{
						if(substr($line, 0, 1) == "(") continue;
						if(substr($line, -1) == ".") $line = substr($line, 0, strlen($line)-1);
						$line = preg_replace("/^(.*?)\t(.*?)$/is", "/// &ltparam name=\"$1\"&gt$2&lt/param&gt<br/>", $line);
						$line = preg_replace("/name=\"(.*?)\[\]\"/is", "name=\"$1\"", $line);
						$line = preg_replace("/name=\"(.*?):(.*?)\"/is", "name=\"$2\"", $line);
						$line = preg_replace("/name=\"&(.*?)\"/is", "name=\"$1\"", $line);
						echo($line);
					}
					
					if ($type == "r")
					{
						if($line == "This function does not return any specific values.") {
							$type = 'i';
							continue;
						}
						if(substr($line, -1) != ".") $line .= ".";
						$returns[] = $line;
					}

					if ($type == "f")
					{
						if (substr($line, 0, 13) == "The following") continue;
						if (substr($line, 0, 4) == 'NPC:') {
							$line = substr($line, 4);
						}
						$name = substr($line, 0, strpos($line, ":"));
						echo("/// &lt;seealso name=\"{$name}\"/&gt;<br/>");
					}

					if ($type == "c")
					{
						if (substr($line, 0, 13) == "The following") continue;
						$name = substr($line, 0, strpos($line, ":"));
						echo("/// &lt;seealso name=\"{$name}\"/&gt;<br/>");
					}
				}
				
				if (count($returns) == 1)
				{
					echo("/// &ltreturns&gt{$returns[0]}&lt/returns&gt<br/>");
				}
				elseif (count($returns) > 0)
				{
					echo("/// &ltreturns&gt<br/>");
					foreach($returns as $r)
					{
						echo("///\t{$r}");
						if($r != $returns[count($returns)-1]) echo("&lt;p/&gt;");
						echo("<br/>");
					}
					echo("/// &lt/returns&gt<br/>");
				}
				
				echo('</span>');
				ob_end_flush();
		
				echo <<<SCRIPT
<script type="text/javascript">
function selectText(element) {
	var doc = document;
	var text = doc.getElementById(element);
	if (doc.body.createTextRange) { // ms
		var range = doc.body.createTextRange();
		range.moveToElementText(text);
		range.select();
	} else if (window.getSelection) { // moz, opera, webkit
		var selection = window.getSelection();            
		var range = doc.createRange();
		range.selectNodeContents(text);
		selection.removeAllRanges();
		selection.addRange(range);
	}
}
selectText('copy');
</script>
SCRIPT;
			}
		?>
	</div>
</body>
</html>
