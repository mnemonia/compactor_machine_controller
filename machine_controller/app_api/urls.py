from django.urls import path
from rest_framework.urlpatterns import format_suffix_patterns
from app_api import views

urlpatterns = [
    path('param/', views.ParamList.as_view()),
    path('param/<int:param_id>/', views.ParamDetail.as_view()),
    path('sensor/', views.SensorList.as_view()),
    path('state/', views.StateList.as_view()),
]

urlpatterns = format_suffix_patterns(urlpatterns)