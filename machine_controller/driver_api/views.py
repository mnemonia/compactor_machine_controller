from driver_api.models import Command, Param
from driver_api.serializers import CommandSerializer, ParamSerializer, ConfigParamValueSerializer
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

class CommandList(generics.ListAPIView):
    queryset = Command.objects.filter(must_run=True)
    serializer_class = CommandSerializer

class CommandDetail(generics.RetrieveUpdateAPIView):
    queryset = Command.objects.filter()
    serializer_class = CommandSerializer
    lookup_field = "command_id"
