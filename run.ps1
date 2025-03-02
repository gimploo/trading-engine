if (-not(Test-Path bin)) {
    New-Item -ItemType Directory -Path bin | Out-Null
    cmake -G "Ninja" -B bin 
    cmake --build bin 
} else {
    cmake --build bin 
}



# Run the executable only if the build succeeds
if ($?) {
    Copy-Item ./bin/compile_commands.json ./
    & "./bin/TradingEngine.exe"
} else {
    Write-Host "Build failed. Exiting..."
    exit 1
}

