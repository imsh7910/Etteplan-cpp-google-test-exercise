# C++ / Google Test / GitHub Actions – temperaturvalidering

[![C++ / Google Test](https://github.com/imsh7910/Etteplan-cpp-google-test-exercise/actions/workflows/cpp-tests.yml/badge.svg)](https://github.com/imsh7910/Etteplan-cpp-google-test-exercise/actions/workflows/cpp-tests.yml)
[![Postman API-tester](https://github.com/imsh7910/Etteplan-cpp-google-test-exercise/actions/workflows/postman.yml/badge.svg)](https://github.com/imsh7910/Etteplan-cpp-google-test-exercise/actions/workflows/postman.yml)

En liten övning i testdesign och automatiserad testkörning. Funktionen godkänner temperaturer mellan -40 °C och 85 °C, inklusive gränsvärden, och avvisar tal utanför intervallet samt NaN och oändlighet.

## Innehåll

- **C++17-funktion** för temperaturvalidering (`src/`, `include/`)
- **Enhetstester med Google Test**: positiva fall, gränsvärden och ogiltiga indata (`tests/`)
- **API-tester med Postman/Newman** mot Restful-booker (`Postman/`)
- **CI med GitHub Actions**: två separata workflows

## Kom igång

Krav: Git, CMake (minst 3.20) och en C++17-kompilator. Google Test hämtas automatiskt av CMake.

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

API-tester lokalt:

```bash
npm install --global newman
newman run Postman/Restful-booker.postman_collection.json --env-var "baseUrl=https://restful-booker.herokuapp.com"
```

## CI

- **C++ / Google Test**: bygger med CMake och kör enhetstester vid varje push och PR.
- **Postman API-tester**: kör Postman-collectionen med Newman, separat från enhetstesterna.

## Övning: se ett rött test och laga felet

1. Ändra i `src/temperature_validator.cpp` operatorn `celsius <= 85.0` till `celsius < 85.0`.
2. Bygg och kör testerna. Testet för övre gränsvärdet ska fallera.
3. Läs felutskriften: vilket test misslyckades, vilket värde gavs och vilket förväntades?
4. Återställ operatorn till `<=` och kontrollera att testerna blir gröna.
5. Committa, pusha och kontrollera att körningen i **Actions** också blir grön.

## Vad projektet visar

- testdesign: positiva fall, gränsvärden och ogiltiga indata
- Google Test med `TEST`, `EXPECT_TRUE` och `EXPECT_FALSE`
- CMake och CTest
- felsökning med tydliga testresultat
- Git och CI-resultat i GitHub Actions

Övningen är fristående och innehåller inga riktiga produkt- eller kunddata.
