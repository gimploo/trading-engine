if (-not(Test-Path build)) {
    New-Item -ItemType Directory -Path build | Out-Null
    cmake -G "Ninja" -B build 
    cmake --build build 
} else {
    cmake --build build 
}



# Run the executable only if the build succeeds
if ($?) {
    Copy-Item ./build/compile_commands.json ./
    & "./build/TradingEngine.exe"
} else {
    Write-Host "Build failed. Exiting..."
    exit 1
}

