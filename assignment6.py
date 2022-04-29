import random as r

print("Welcome to the Expert System!".center(60,'-'))

questions = [
    "How good is your workspace ?",
    "overall Rating for your Workspace",
    "Rating for you collegues",
    "Behaviour of your Manager:",
    "Do your manager have significant knowledge of the project ?",
    "Are you able to cope up with company flow?",
]


def get_result(score):
    if score<=1*MAX_QUESTIONS:
        print("You seem Happy with your work ! :)")
    elif score <= 2*MAX_QUESTIONS:
        print("You're liking your work ;)")
    elif score <= 3*MAX_QUESTIONS:
        print("It looks like you're not happy with your job")
    elif score <= 4*MAX_QUESTIONS:
        print("It looks like you hate your job")
    else:
        print("It looks like you're about to quit.")

l = []

MAX_QUESTIONS = len(questions)
for i in range(MAX_QUESTIONS):
    l.append(0)


while 0 in l:
    qno = r.randint(0,MAX_QUESTIONS-1)
    if l[qno] == 0:
        print(questions[qno])
        exit = False
        while not exit:
            l[qno] = int(input('1.Excellent\t2.Good\t3.Okay\t4.Not Good\t5.Bad\n Enter Your choice:'))
            exit = True
            if l[qno] > 5 and l[qno] < 0:
                print("please Enter Valid Choice.")
                exit = False
get_result(sum(l))