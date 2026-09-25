# C++ / Google Test / GitHub Actions – testövning

En liten övning i testdesign och automatiserad testkörning. Funktionen godkänner temperaturer mellan -40 °C och 85 °C, inklusive gränsvärden, och avvisar tal utanför intervallet samt NaN och oändlighet.

## Flödet

1. Skapa ett nytt, tomt repository på GitHub, till exempel `cpp-google-test-exercise`.
2. Packa upp zip-filen och öppna terminalen i projektmappen.
3. Installera Git, CMake (minst 3.20) och en C++17-kompilator. Google Test hämtas automatiskt av CMake.
4. Kör lokalt:

   ```bash
   cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
   cmake --build build --parallel
   ctest --test-dir build --output-on-failure
   ```

5. Skapa Git-historik och koppla till ditt GitHub-repository (byt ut URL:en mot din egen):

   ```bash
   git init
   git add .
   git commit -m "Add C++ temperature validation tests"
   git branch -M main
   git remote add origin https://github.com/DITT-ANVÄNDARNAMN/cpp-google-test-exercise.git
   git push -u origin main
   ```

6. Öppna fliken **Actions** i GitHub. Workflowen bygger projektet och kör tester vid varje push och pull request.

## Övning: se ett rött test och laga felet

1. Ändra i `src/temperature_validator.cpp` operatorn `celsius <= 85.0` till `celsius < 85.0`.
2. Bygg och kör testerna igen. Testet för övre gränsvärdet ska fallera.
3. Läs felutskriften: vilket test misslyckades, vilket värde gavs och vilket resultat förväntades?
4. Återställ operatorn till `<=`, kör testerna och kontrollera att de blir gröna.
5. Spara ändringen med Git och pusha. Kontrollera i **Actions** att den automatiska körningen också blir grön.

## Vad du tränar på

- positiva fall, gränsvärden och ogiltiga indata
- Google Test med `TEST`, `EXPECT_TRUE` och `EXPECT_FALSE`
- byggning med CMake och testkörning med CTest
- felsökning med tydliga testresultat
- Git-commit, push och CI-resultat i GitHub Actions

Använd bara ett repository som du själv äger eller har tillstånd att ändra. Den här övningen är fristående och innehåller inga riktiga produkt- eller kunddata.
