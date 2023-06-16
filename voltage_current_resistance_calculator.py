def calculate_voltage_current_resistance():
    choice = input("What would you like to calculate? (voltage, current, resistance): ")

    if choice == "voltage":
        current = float(input("Enter the current value (in amperes): "))
        resistance = float(input("Enter the resistance value (in ohms): "))
        voltage = current * resistance
        print("The voltage is:", voltage, "volts")
    elif choice == "current":
        voltage = float(input("Enter the voltage value (in volts): "))
        resistance = float(input("Enter the resistance value (in ohms): "))
        current = voltage / resistance
        print("The current is:", current, "amperes")
    elif choice == "resistance":
        voltage = float(input("Enter the voltage value (in volts): "))
        current = float(input("Enter the current value (in amperes): "))
        resistance = voltage / current
        print("The resistance is:", resistance, "ohms")
    else:
        print("Invalid choice!")

calculate_voltage_current_resistance()
