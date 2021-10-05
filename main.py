def letToGrade(grade):
    grade = str(grade.upper())
    if grade == "A+":
        numGrade = 10
    elif grade == "A":
        numGrade = 9
    elif grade == "B":
        numGrade = 8
    elif grade == "C":
        numGrade = 7
    elif grade == "D":
        numGrade = 6
    elif grade == "F":
        numGrade = 5
    elif grade == "I":
        numGrade = 0
    else:
        print("Enter a valid grade!\n")
        numGrade = None
    return numGrade


def GradeFunction():
    courseCredits = [4, 3, 3, 3, 3, 2, 1, 1, 2]
    gradeList = [_ for _ in input("Enter the grades in the order above, as a list (Enter I for incomplete):\nExample: "
                                  "A+ A A B B A etc.\n").split()] 
    numerList = [int(letToGrade(x)) for x in gradeList if letToGrade(x) != 0]
    for item in gradeList:
        if item.upper() == "I":
            courseCredits.pop(gradeList.index(item))
    resList = [numerList[i] * courseCredits[i] for i in range(len(numerList))]
    total = sum(resList)
    return total/(sum(courseCredits))


def main():
    if str(input("What was your first cycle: [P]HY/[C]HEM:\n")).upper() == "P":
        print("Course order is [MAT PHY MOS BE BME ENG PHYLAB WORKSHOP EG1]")
        x = GradeFunction()
        print("Course order is [MAT CHEM BIO BET PSUC EVS CHEMLAB PSUCLAB EG2]")
        y = GradeFunction()
    else:
        print("Course order is [MAT CHEM BIO BET PSUC EVS CHEMLAB PSUCLAB EG1]")
        x = GradeFunction()
        print("Course order is [MAT PHY MOS BE BME ENG PHYLAB WORKSHOP EG2]")
        y = GradeFunction()

    print((x + y) / 2)


main()

input("Press enter to continue.")
