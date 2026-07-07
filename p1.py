def process(name, *args, **kwargs):
	print(f"Name: {name}")
	print("Positional args: ", args)
	print("Keyword args" , kwargs)

# process("Main Node", 1,2,3 , status="Active" , retires=5)  

def format_name(first_name, last_name=None):
				if last_name:
					return f"{first_name.capitalize()} {last_name.capitalize()}"
				return first_name.capitalize()


def multiply(*args):
	product =1
	for num in args:
		product *=num
	return product

def build_profile(username, **kwargs):
    return {"username": username, **kwargs}

       
def split(numbers):
	evens = [ num for num in numbers if num% 2 == 0]
	odds =[ num for num in numbers if num %2 != 0]
	return {"evens": evens, "odds":odds}


def common(dev1_skills , dev2_skills):
	
    return list(set(dev1_skills) & set(dev2_skills))
    

def parse_command(raw_string):
	s = raw_string.strip().capitalize().split()
	print(s) 

parse_command("  HEY Sinamika AyE Jude good   handshake   ")


def parse_expense(amount_s):
	try:
		amount = float(amount_s)
		print(f"Expense logged: {amount}")
	except ValueError:
		print("please enter a valid num")
	finally:
		print("Parsing attempt finished")
		
parse_expense("500")
parse_expense("pizza")
	
def safe_divide(a,b):
	try:
		return a/b
	except ZeroDivisionError:
		return "Cannot divide by zero"
	finally:
		print("running finally")

def validate_username(username):
	if len(username) <3:
		raise ValueError("username too short")
	return "valid"
	

print(safe_divide(10, 2))