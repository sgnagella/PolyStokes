import numpy as np
import os
import matplotlib.pyplot as plt

def main():
    # load the cpp results
    # os.chdir('config/data/beta_0.1')
    cpp_results = np.load("central_particle_azimuth_vs_time.npy")
    cpp_times = np.load("central_particle_azimuth_vs_time.npy")
    
    # load the python results
    python_file = "/home/sgnagella/projects/optical_tweezers_sd/python_SD_w_N_FENE_Dumbell_ReformedM_kT_0_precond_equal_sphere/data/beta_0.1/central_particle_azimuth.npy"
    python_results = np.load(python_file)
    flag = True
    
    fig, ax = plt.subplots()
    ax.plot(cpp_results, '-k', lw=2, label='C++')
    ax.plot(python_results[:-1], '-r', lw=2, label='Python')
    ax.set_xlabel('Time')
    ax.set_ylabel('Central Particle Azimuth')
    ax.legend()
    plt.show()
    
    return

if __name__ == "__main__":
    main()