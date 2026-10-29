FUNCTION calcFee(minutes) RETURNS Integer
    DECLARE result AS Integer
    IF minutes <= 30 THEN
        SET result = 0
    ELSE IF minutes <= 60 THEN
        SET result = 1500
    ELSE IF minutes <= 120 THEN
        SET result = 3500
    ELSE
        SET result = 3500 + Floor((minutes - 120 + 59) / 60) * 1000
    END IF
    RETURN result
END FUNCTION

FUNCTION printRow(n, mins, fee, plate)
    OUTPUT n & " | " & mins & " | " & fee & " | " & plate
END FUNCTION

MAIN
    DECLARE plate, maxPlate AS String
    DECLARE entryHour, entryMinute, exitHour, exitMinute AS Integer
    DECLARE entryTotal, exitTotal, parkedMinutes, fee AS Integer
    DECLARE totalIncome, maxMinutes, i AS Integer

    SET totalIncome = 0
    SET maxMinutes = 0
    SET maxPlate = ""
    SET fee = 0

    OUTPUT "No | Minut | Tulbur | Dugaar"

    FOR i = 1 TO 5
        OUTPUT "Mashinii dugaar:"
        INPUT plate

        DO
            OUTPUT "Orson tsag:"
            INPUT entryHour
            OUTPUT "Orson minut:"
            INPUT entryMinute
            OUTPUT "Garsan tsag:"
            INPUT exitHour
            OUTPUT "Garsan minut:"
            INPUT exitMinute
            SET entryTotal = entryHour * 60 + entryMinute
            SET exitTotal = exitHour * 60 + exitMinute
        WHILE (entryHour < 0 OR entryHour > 23 OR
               entryMinute < 0 OR entryMinute > 59 OR
               exitHour < 0 OR exitHour > 23 OR
               exitMinute < 0 OR exitMinute > 59 OR
               exitTotal <= entryTotal)

        SET parkedMinutes = exitTotal - entryTotal
        SET fee = CALL calcFee(parkedMinutes)
        SET totalIncome = totalIncome + fee

        IF parkedMinutes > maxMinutes THEN
            SET maxMinutes = parkedMinutes
            SET maxPlate = plate
        END IF

        CALL printRow(i, parkedMinutes, fee, plate)
    END FOR

    OUTPUT "Niit orlogo: " & totalIncome
    OUTPUT "Hamgiin udaan: " & maxPlate & " (" & maxMinutes & " min)"
END MAIN