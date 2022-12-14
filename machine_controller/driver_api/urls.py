from django.urls import path
from rest_framework.urlpatterns import format_suffix_patterns
from driver_api import views

urlpatterns = [
    path('param/', views.ParamList.as_view()),
    path('param/<int:param_id>/', views.ParamDetail.as_view()),
    path('config/value/', views.ConfigParamValueList.as_view()),
    path('command/', views.CommandList.as_view()),
    path('command/<int:command_id>/', views.CommandDetail.as_view()),
]

urlpatterns = format_suffix_patterns(urlpatterns)