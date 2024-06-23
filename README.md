# Get-Next-Line-42

<p>Նպատակը - կարդալ buffer-ի չափով և տեղավորել մեր static line-ի մեջ: text.txt հանդիսանում է մեր gnl-ի կանչվող fd(3) (զբաղված են fd < 3) Երբ buffer-ում հանդիպում է '\n' և տեքստի շարունակությունը, մենք պետք է այն բաժանենք իրարից և տեղաորենք next static line-ում` նոր տողում: buffer-ից հետո հայտարարում ենք '\0', որպեսզի հայտարարենք վերջը, այլապես buffer-ը կլցնենք trash-ով:
<p>Երբ հանդիպվում է '\n' մենք առանձնացնում ենք “look of our gnl.”-ը “Nice.”-ից, այս կոդում հաշվում ենք “look of our gnl.”-ի size-ը, static line-ից հանելով “Nice.”-ի չափը: Այնուհետև տեղափոխում ենք “Nice.”-ը next static line, join անելով հաջորդող buffer-ը, իսկ “look of our gnl.”-ը պահպանում մեր ներկա static line-ում: Վերջում free (line)-ը:

<p>The goal is to read as a buffer size then fit in our static line. text.txt is our gnl fd (3) (busy fd <3) When the '\n' and text after it appears in the buffer, we need to separate it and place it in a new line - next static line.
<p> After buffer we declare '\0' to declare the end, otherwise we will fill the buffer with trash
When we find '\n' we divide “look of our gnl.” by “Nice.”. In this code we calculate the size of 2 by subtracting 3 from 1. Then move 3 to the next static line join the next buffer, and save 2 to our current static line. free 1 at the end

	       Hello World I am Programmer, let’s take a look of our gnl.
Nice. It works. Yep
buffer      [---------------------------] that reads the text of its size
	       Hello World I am Pro grammer, let’s take a  look of our gnl.\nNice..
1										2		3
static line [---------------------------][---------------------------][--------------------'\n'------] brake ;


       Hello World I am Pro grammer, let’s take a  look of our gnl.'\0'
1										2
static line [---------------------------][---------------------------][--------------------]'\0'
	

	     Nice. It works. Yep
	    	       3	  +	buffer
next static line [------][---------------------------][---------------------------][---------------------------]...

#### Bonus
<p>Ուղակի կանչվում է <limits.h> գրադարանը որպեսզի հայտարարվի MAX fd(3, 4, 5…), որը ստանդարտով 65536 (OPEN_MAX) է և static line[fd], բացի while ցիկլից, որտեղ ստուգում ենք '\n'
<p>The <limits.h> library is simply called to declare MAX fd (3, 4, 5…), which by default is 65536 (OPEN_MAX) and static line [fd], except for the while loop where we check '\n'