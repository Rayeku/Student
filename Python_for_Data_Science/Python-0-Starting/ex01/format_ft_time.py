from datetime import datetime
import time

today = datetime.now().strftime("%b %d %Y")
time_passed = time.time()
coma_format = f"{time_passed:,.4f}"
scientist_format = f"{time_passed:.2e}"

print("Seconds since January 1, 1970: " + coma_format)
print(" or " + scientist_format + " in scientific notation")
print(datetime.now().strftime("%b %d %Y"))
