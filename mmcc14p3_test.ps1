Write-Progress -Id 0 -Activity "Compiling:" -Status "Compiling..."
g++ -std=gnu++17 c.cpp -o c -Ofast && g++ -std=gnu++17 c1.cpp -o c1 -Ofast
Write-Progress -Id 0 -Activity "Compiling:" -Status "Compiled."
$n = 50
for ($i = 1; $i -le $n; $i++) {
    Write-Progress -Id 0 -Activity "Testing: " -Status "Case $i of $n..." -PercentComplete (100 * $i / $n)
	py test.py
	$a = Get-Content .\data.txt | .\c.exe
	$b = Get-Content .\data.txt | .\c1.exe
    Write-Progress -Id 1 -ParentId 0 -Activity "Last output: " -Status "$a $b"
	if ($a -ne $b) {
		Write-Host "$a $b"
		break
	}
}