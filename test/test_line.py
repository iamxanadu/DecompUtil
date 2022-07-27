#!python
# %%
import sys
sys.path.append('../build')
import decomp_util

from decomp_util import LineSegment2D
from numpy import array

decomp = LineSegment2D(array([-1.5, 0.0]), array([1.5, 0.3]))
decomp.set_obs([array([0.0, 0.2])])
decomp.set_local_bbox(array([2, 2]))
decomp.dilate(0)

elips = decomp.get_ellipsoid()


# %%
