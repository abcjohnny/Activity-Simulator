# Activity-Simulator

#Setting up

Setup Github SSH key access on the machine you plan to use this on.

Run these commands to make sure you get the commits to show on your account's activity.

```
git config --global user.name "Your Name"
git config --global user.email "your-email@example.com"
```
Create a private github repo, this will be the repo used to simulate activity. (If you want to run the pre-compiled executable name this repo "The test subject", which will mean the folder name is "The-test-suject", or else you'll have to compile it with your prefered name.

Create a "log.txt" file in the repo you just created, this will be where changes are made.

Clone both this repo and the repo you created to the same folder. It's important both repositories are at the same level or the program will not work.

If you chose to name your private repo something else change line #30 in main.cpp and compile.

#Scheduling the executable

Edit cronjobs for you user

```
crontab -e
```

add the line to your cron scheduler, this particular line runs the executable every day at 14:00

```
0 14 * * * /path/to/simulator
```

Save and exit. 
