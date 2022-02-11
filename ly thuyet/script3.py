titles = list()

for i in range(1, 46):
    number = str(i) if i > 9 else '0' + str(i)
    filename = 'exam' + number + '.md'

    f = open(filename, "r")
    titles.append(f.readline().strip())
    f.close()

for i in range(1, 46):
    number = str(i) if i > 9 else '0' + str(i)
    filename = 'exam' + number + '.md'

    next_number = i % 45 + 1
    next_number = str(next_number) if next_number > 9 else '0' + str(next_number)

    next_filename = 'exam' + next_number  + '.md'

    prev_number = (i - 2) % 45 + 1
    prev_number = str(prev_number) if prev_number > 9 else '0' + str(prev_number)
    prev_filename = 'exam' + prev_number + '.md'

    curfile = open(filename, 'a')
    next_link = '[' + titles[i % 45][2:] + ']' + '(./' + next_filename[:-3] + ')\n'
    prev_link = '[' + titles[(i - 2) % 45][2:] + ']' + '(./' + prev_filename[:-3] + ')\n'

    curfile.write('\n\n**Следующий вопрос:**  ' + next_link)
    curfile.write('\n\n**Предыдущий вопрос:**  ' + prev_link)
    curfile.close()
