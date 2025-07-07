# database structure?

we dont habe to make other tables for now, this should be enough

- main table:

| eventid | userid | eventname | datetimebegin | datetimeend | isfullday | groupid |
| ------- | ------ | --------- | ------------- | ----------- | --------- | ------- |


- group table:

| groupid | groupname |
| ------- | --------- |


- user table:

| userid | username | permissions and shit, think about this later |
| ------ | -------- | -------------------------------------------- |


## event types: 

1. that have datetimebegin and datetime end
- isfullday = false
- datetimebegin, datetimeend != none

2. that only have a date to them 
- isfullday = true
- datetimebegin is at 00:00 or whatever, we only want the date
- datetimeend is whatever, we dont care

## event groups

have a group table duh, a later feauture could be sharing groups

## user permissions

[~] give users permissions to view only their shit (figure this out later)

there would always be a superadmin that views everything but its fiiine

## other notes

[~] how to do notifications? probably have another collumn (figure this out later)

as an idea for later, we can store enctypted data
client would their private key and give us the public one
data base admin will be able to see our shit but not read it

but its fine since we want this to be self hostable
