from operator import itemgetter
import sys
current_year = None
year_tot = [0]
year_male = [0]
year_fem = [0]
month_tot = [0]
month_male = [0]
month_fem = [0]
specyear = 2000
i = 1
while i<40:
	year_tot.append(0)
	year_male.append(0)
	year_fem.append(0)
	i += 1
i = 0
while i<12:
	month_tot.append(0)
	month_male.append(0)
	month_fem.append(0)
	i += 1
year = None
for line in sys.stdin:
    line = line.strip()
    sex, month, year = line.split(' ')
    sex = int(sex)
    month = int(month)
    year = int(year)
    year_tot[year-1980] += 1
    if sex == 0:
    	year_male[year-1980] += 1
    else:
    	year_fem[year-1980] += 1
    if year == specyear:
    	month_tot[month-1] += 1
    	if sex == 0:
    		month_male[month-1] += 1
    	else:
    		month_fem[month-1] += 1
i = 0
while i<40:
	if year_tot[i] == 0:
		i += 1
		continue
	print('Year %d Total: %d' %(i+1980, year_tot[i]))
	print('Males: %d' %(year_male[i]))
	print('Females: %d' %(year_fem[i]))
	print('\n')
	i += 1
print('Year %d'% (specyear))
i = 0
while i<12:
	if month_tot[i] == 0:
		i += 1
		continue
	print('Month %d Total: %d' %(i+1, month_tot[i]))
	print('Males: %d' %(month_male[i]))
	print('Females: %d' %(month_fem[i]))
	print('\n')
	i += 1