

$Path = Split-Path $MyInvocation.MyCommand.Definition

for ($i = 1;$i -le 18;$i++)
{
New-Item -Path $Path -Name "EX H$i" -ItemType Directory
}

echo "Done"
