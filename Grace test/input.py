import serial
import time
import serial.tools.list_ports

print("Checking connection...")
time.sleep(2)

def portCheck(): #checks if mac plug in... EDIT FOR OTHER OS...
    ports = serial.tools.list_ports.comports()
    for port in ports:
        if 'usbmodem' in port.device:
            return port.device
    return False


def intro(): ##Finish 9 and multiple
    print("""
┌────────── ⋆⋅☆⋅⋆ ──────────┐
|  Please enter an Option!  |
|---------------------------|
| 1.) Point                 |
| 2.) Wings Up              |
| 3.) Thumbs Up             |
| 4.) Rock On               |
| 5.) Peace Sign            |
| 6.) All Fingers           |         
| 7.) Birdie                |
| 8.) Neutral               |
| 9.) TEST                  | 
└────────── ⋆⋅☆⋅⋆ ──────────┘  
          """) 


def main():
    port = portCheck()

    while not port:
        print("Please reconnect port!")
        time.sleep(3)
        port = portCheck()

    ser = serial.Serial(port, 9600, timeout = 1)
    while port:
        intro()                                     #calls the intro function from above

        choice = input("Enter Your Choice --> ")    #holds user choice in a variable

        try:
            command = f"{choice}\n".encode('utf-8')     #formats the data to bytes to be sent to arduino
            ser.write(command)                          #SENDS COMMAND TO ARDUINO!
            time.sleep(0.1) 

            while ser.in_waiting > 0:                   # Shows whatever arduinos is printing out...
                response = ser.readline().decode('utf-8', errors = 'replace').strip()
                print(f"{response}")

            if choice == '9':            #Remember, python sends instructions to arduinos via a STRING... NOT an integer!!!
                channel = input()
                command2 = f"{channel}\n".encode('utf-8')     #formats the data to bytes to be sent to arduino
                ser.write(command2)                          #SENDS COMMAND TO ARDUINO!
                time.sleep(0.1) 
                
                while ser.in_waiting > 0:
                    response2 = ser.readline().decode('utf-8', errors = 'replace').strip()
                    print(f"{response2}")

        except:
            print("Port error! Please reconnect!")
            time.sleep(5)
            portCheck()

            if portCheck() is not False:
                print("Port reconnected!")
            else:
                print("Port Timed out!")
                ser.close()                                 #Closes program when port timed out


                                    
    
    
    

############# initiates Main ############
if __name__ == "__main__":
    main()

