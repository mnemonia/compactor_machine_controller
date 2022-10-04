from driver_api.models import Param
from driver_api.serializers import ParamSerializer, ConfigParamValueSerializer
from django.http import Http404
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from rest_framework import generics


class ParamList(generics.ListCreateAPIView):
    queryset = Param.objects.all()
    serializer_class = ParamSerializer

class ParamDetail(generics.RetrieveUpdateDestroyAPIView):
    queryset = Param.objects.all()
    serializer_class = ParamSerializer
    lookup_field = "param_id"

class ConfigParamValueList(generics.ListAPIView):
    queryset = Param.objects.filter(param_type="NOMINAL")
    serializer_class = ConfigParamValueSerializer
