
if (-not(Test-Path build)) {
    New-Item -ItemType Directory -Path build | Out-Null
    Set-Location build
    cmake ..
    cmake --build . 
} else {
    Set-Location build
    cmake --build . 
}


# Run the executable only if the build succeeds
if ($?) {
    & "./Debug/TradingEngine.exe"
} else {
    Write-Host "Build failed. Exiting..."
    exit 1
}

Set-Location ..
