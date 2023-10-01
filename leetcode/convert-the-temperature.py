class Solution:
    def convertTemperature(self, Celsius: float) -> List[float]:
        Kelvin = Celsius + 273.15
        Fahrenheit = Celsius * 1.80 + 32.00
        return [Kelvin, Fahrenheit]