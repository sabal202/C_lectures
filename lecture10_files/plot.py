import matplotlib.pyplot as plt
import numpy as np
l = """170 56
185 76
183 70
172 76
179 72
185 60
197 75
180 70
181 75"""
p = [(int(i.split()[0]), int(i.split()[1])) for i in l.split("\n")]
fig, ax = plt.subplots(figsize=(15,10))
ax.set_xlim(xmin = 100, xmax = 250)
ax.set_ylim(ymin = 0, ymax = 100)
ax.scatter(x=[i[0] for i in p], y = [i[1] for i in p], marker = 'o', c='r')
ax.set_xlabel("$Рост$")
ax.set_ylabel("$Вес$")
x = np.linspace(110, 240)


y = 69.375000 + (7.016721 / 7.888877) * 0.365545 * (x - 181.375000)
#y = 80.400000 + (9.425497 / 7.977468) * 0.959682 *(x - 173.600000)

ax.plot(x, y)
plt.show()
"àáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ 1234567890-!?(),.ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ