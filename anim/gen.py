import numpy as np
import matplotlib.pyplot as plt


for frame in range(200):
    x = []
    for i in range(2000):
        y = 0.321874952*i
        if np.random.randint(9) %2 ==0:
            x.append(y)
    plt.plot(x,np.sin(x),'--')
    plt.savefig(f"imgs/{frame}.png")
    plt.close()
    del(x)
    print(frame)

