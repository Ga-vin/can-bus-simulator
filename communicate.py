#!/usr/bin/python
import serial
import syslog
import time

class Simulator(object):
    """docstring for Simulator"""

    #----CONSTANTS
    #Codes to communicate with the arduino
    KEEPALIVE   = 0x01
    READ        = 0x02
    WRITE       = 0x03
    DONE        = 0x04
    EXIT        = 0x10
    ERROR       = 0xA0

    #The following line is for serial over GPIO
    PORT = '/dev/ttyACM0'

    #----FIELDS
    in_file_name = "input.sim"
    out_file_name = "output.sim"


    def __init__(self):
        super(Simulator, self).__init__()
        self.arduino = serial.Serial(self.PORT, 9600, timeout=5)


    def wait_for_code(self, code, timeout=5):
        start = time.time()
        #Wait for a heartbeat
        while(time.time() - start < timeout):
            if(ard.inWaiting()):
                result = ard.read(ard.inWaiting())
                if(self.ERROR in result):
                    raise ValueError("Arduino threw error")
                elif(code in result):
                    return True
            time.sleep(0.05)
        return False

    def send_input(self):
        in_file = open(self.in_file_name, "r")

        if(!self.wait_for_code(self.KEEPALIVE)):
            raise ValueError("Arduino timed out in keepalive")

        #Tell the arduino to start reading
        ard.write(self.READ)

        for line in in_file:
            #Make sure that the line has a time and a command
            assert(len(line.split(":") == 2)

            #Wait for it to acknowledge
            if(!self.wait_for_code(self.READ)):
                raise ValueError("Arduino timed out in read")

            #Write one line of the file
            ard.write(line)

        if(!self.wait_for_code(self.READ)):
            raise ValueError("Arduino timed out in read")

        #Tell the arduino to finish reading
        ard.write(self.DONE)

        #Verify that the arduino has gone back to it's default state
        if(!self.wait_for_code(self.KEEPALIVE)):
            raise ValueError("Arduino timed out in read")

    def get_output(self):
        self.out_file.write("{0:08d}:{}".format(time_stamp, message))


def main():
    sim = Simulator()
    sim.send_input()

if __name__ == '__main__':
    main()
