function createNumber(number) {
    switch (number) {
        case "0": 
                return {
                 firstLine:     "  -- ",
                 secondLine:    " |  |",
                 thirdLine:     "     ",
                 fourthLine:    " |  |",
                 fifthLine:     "  -- "
                };
        case "1": 
        return {
            firstLine:     "     ",
            secondLine:    "    |",
            thirdLine:     "     ",
            fourthLine:    "    |",
            fifthLine:     "     "
           };
        case "2": 
        return {
            firstLine:     "  -- ",
            secondLine:    "    |",
            thirdLine:     "  -- ",
            fourthLine:    " |   ",
            fifthLine:     "  -- "
           };
        case "3": 
        return {
            firstLine:     "  -- ",
            secondLine:    "    |",
            thirdLine:     "  -- ",
            fourthLine:    "    |",
            fifthLine:     "  -- "
           };
        case "4": 
        return {
            firstLine:     "     ",
            secondLine:    " |  |",
            thirdLine:     "  -- ",
            fourthLine:    "    |",
            fifthLine:     "     "
           };
        case "5": 
        return {
            firstLine:     "  -- ",
            secondLine:    " |   ",
            thirdLine:     "  -- ",
            fourthLine:    "    |",
            fifthLine:     "  -- "
           };
        case "6": 
        return {
            firstLine:     "  -- ",
            secondLine:    " |   ",
            thirdLine:     "  -- ",
            fourthLine:    " |  |",
            fifthLine:     "  -- "
           };
        case "7": 
        return {
            firstLine:     "  -- ",
            secondLine:    "    |",
            thirdLine:     "     ",
            fourthLine:    "    |",
            fifthLine:     "     "
           };
        case "8": 
        return {
            firstLine:     "  -- ",
            secondLine:    " |  |",
            thirdLine:     "  -- ",
            fourthLine:    " |  |",
            fifthLine:     "  -- "
           };
        case "9": 
        return {
            firstLine:     "  -- ",
            secondLine:    " |  |",
            thirdLine:     "  -- ",
            fourthLine:    "    |",
            fifthLine:     "     "
           };
    }
}

function print7segNumber(digits) {
    var len = digits.length;
    var i = 1;
    var segNumbers = createNumber(digits[0]);

    while (i < len) {
        var newSegNumbers = createNumber(digits[i]);

        segNumbers.firstLine = segNumbers.firstLine.concat(newSegNumbers.firstLine);
        segNumbers.secondLine = segNumbers.secondLine.concat(newSegNumbers.secondLine);
        segNumbers.thirdLine = segNumbers.thirdLine.concat(newSegNumbers.thirdLine);
        segNumbers.fourthLine = segNumbers.fourthLine.concat(newSegNumbers.fourthLine);
        segNumbers.fifthLine = segNumbers.fifthLine.concat(newSegNumbers.fifthLine);

        i++;
    }    

    console.log(segNumbers.firstLine);
    console.log(segNumbers.secondLine);
    console.log(segNumbers.thirdLine);
    console.log(segNumbers.fourthLine);
    console.log(segNumbers.fifthLine);

}


function writeLine(number) {
    var n = number.split(",")[0];
    let digits = number.split(",")[1];

    if (digits < 0) {
        console.log("Error.");
        return;
    }

    for (var i = 1; i <= n; i++) {
        print7segNumber(digits);
    }

}

function writeNumbers(numbers) {
    if (!numbers.includes("0,0")) {
        console.log("Error.");
    }

    var lines = numbers.split("\n");
    var len = lines.length;

    for (var i = 0; i < len-1; i++) {
        writeLine(lines[i]);
    }
}

writeNumbers("1,123\n" +
             "2,456\n" + 
             "2,789\n" +
             "0,0");