home = open('Home.md', "w")
home.write('# Компьютерная графика 2020\n')
home.write('## Экзамен\n| Тема | Готовность |\n| ------ | ------ |\n')
sidebar = open('_Sidebar.md', "w")
sidebar.write("### Экзамен\n\n")

for i in range(1, 46):
    number = str(i) if i > 9 else '0' + str(i)
    filename = 'exam' + number + '.md'

    f = open(filename, "r")
    title = f.readline().strip()
    f.close()

    link = '[' + title[2:] + ']' + '(./' + filename[:-3] + ')\n'
    sidebar.write(link)
    home.write('| ' + link + ' | ' + '🙁 ' + ' |\n')
