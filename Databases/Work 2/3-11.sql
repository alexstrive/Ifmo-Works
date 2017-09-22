select Gender, Sum(SickLeaveHours)
	from HumanResources.Employee
	group by Gender